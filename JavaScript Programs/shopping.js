/*
Daniel Brooks, 269416
COP2801, Assignment 4

This program creates 5 albums using the Album class and stores them in an array,
simulates purchases with a loop, and displays all items purchased.
*/

// Create class Album
function Album(title, fName, lName, price, releaseDate, trackListing) {
	this.title = title;
	this.artist = {firstName: fName, lastName: lName};
	this.price = price;
	this.releaseDate = new Date;
	this.releaseDate.setFullYear(releaseDate);
	this.quantity = (Math.ceil(Math.random() * 10));
	this.trackListing = [];
	for (var song in trackListing) {
		this.trackListing[song] = tracklisting[song];
	}

	// Purchase an album
	this.purchase = function() {
		if (this.quantity > 0) {
			this.quantity--;
			return 1;
		}
		else { return -1; }
	}
}

// Create class Cart
function Cart() {
	this.items = [];

	// Add album to cart
	this.add = function(albumToAdd) {
		this.items.push(albumToAdd);
	}

	// Checkout
	this.checkout = function() {
		var totalPurchase = 0;
		console.log("Items purchased:\nAlbum/Artist\t\t\t\t\t\t\t" +
			"Qty\t\tUnit Price\t\tTotal");
		console.log("=====================================================================");
		for (i = 0; i < albumArray.length; i++) { // for each album,
			var quantityPurchased = 0;
			for (j = 0; j < this.items.length; j++) { // search cart
				if (albumArray[i] == this.items[j]) { // for a match, and
					quantityPurchased++; // add to quantity purchased
				}
			}
			if (quantityPurchased != 0) {
				totalPurchase += albumArray[i].price * quantityPurchased;
				console.log(albumArray[i].title + " by " +
					albumArray[i].artist.firstName + " " +
					albumArray[i].artist.lastName);
				console.log("\t\t\t\t\t\t\t\t\t\t" + quantityPurchased + "\t\t" +
					albumArray[i].price + "\t\t   " +
					(albumArray[i].price * quantityPurchased).toFixed(2));
			}
		}
		console.log("=====================================================================");
		console.log("TOTAL PURCHASE:\t\t\t\t\t\t\t\t\t\t\t\t $" + totalPurchase.toFixed(2));
		console.log("=====================================================================");
		console.log("\nRemaining funds: $" + availableFunds.toFixed(2) + "\n");
	}
}

// Create 5 new albums and store in an array
var album1 = new Album("Pageant Material", "Kacey", "Musgraves", 12.99,
	2015, tracklisting = ["High Time", "Dime Store Cowgirl",
	"Late To The Party", "Pageant Material", "This Town", "Biscuits",
	"Somebody To Love", "Miserable", "Die Fun", "Family Is Family",
	"Good Ol’ Boys Club", "Cup Of Tea", "Fine"]);
var album2 = new Album("Middle Cyclone", "Neko", "Case", 7.99, 2009,
	tracklisting = ["This Tornado Loves You", "The Next Time You Say Forever",
	"People Got A Lotta Nerve", "Vengeance Is Sleeping", "Middle Cyclone",
	"Fever", "Magpie To The Morning", "I’m An Animal", "Prison Girls",
	"Don’t Forget Me", "The Pharoahs", "Red Tide"]);
var album3 = new Album("Yakiimo", "Simone", "White", 10.99, 2009,
	tracklisting = ["Bunny In A Bunny Suit", "Candy Bar Killer",
	"Victoria Anne", "Baby Lie Down With Me", "Yakiimo", "A Girl You Never Met",
	"Without A Sound", "Train Song", "Your Stop", "Olivia 101",
	"Let The Cold Wind Blow", "St. Louis Blues"]);
var album4 = new Album("Le prix de l’eden", "Pauline", "Croze", 16.99, 2012,
	tracklisting = ["Dans la ville", "Le prix de l’eden",
	"Aux quatre coins de toi", "Cicatrices", "Quelle heure est-il?",
	"Oui mais", "Le chant de l’orpailleur", "De la joie", "Heures creuses",
	"Cache cache", "Ma rétine"]);
var album5 = new Album("Silver Silver", "Simone", "White", 14.99, 2012,
	tracklisting = ["Flowers In May", "Big Dreams And The Headlines",
	"Never Be That Tough", "We Didn’t Know", "Silver Silver",
	"What The Devil Brings", "Long Moon", "In The Water Where The City Ends",
	"Star", "Frogs", "Now The Revolution", "Every Little Now And Then"]);

var albumArray = [album1, album2, album3, album4, album5];

var availableFunds = 1000;
var myCart = new Cart();
var ableToPurchase = true;

// Loop that simulates purchases until money or inventory is depleted
do {
	ableToPurchase = false;
	for (var i = 0; i < albumArray.length; i++) {
		if (availableFunds > albumArray[i].price) { // If you have money to purchase
			if (albumArray[i].purchase() == 1) { // If inventory, purchase
				myCart.add(albumArray[i]);
				availableFunds -= albumArray[i].price;
				ableToPurchase = true;
			}
		}
	}
} while (ableToPurchase == true); // while the loop iterates with a purchase

// Display the cart and total cost
myCart.checkout();