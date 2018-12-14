/*
Daniel Brooks, 269416
COP2801, Assignment 3.3

This program calculates compound interest of five random investments
for five random rates & time periods and displays the results.
*/

// Declare variables
var F = 0; // future value
var P = 0; // present value
var i = 0; // interest rate
var t = 0; // time, in months

// Generate random investments and time periods
// and calculate the future value
for (var inv = 1; inv <= 5; inv++) {
	P = ((Math.random() * 10) * 100).toFixed(2);
	i = Math.round(Math.random() * 10) * .01;
	t = Math.round(Math.random() * 99 + 1);
	F = calculateFutureValue(P, i, t);
	console.log("Present Value: $" + P);
	console.log("Monthly Interest Rate: " + i);
	console.log("Number of Months: " + t);
	F = F.toFixed(2);
	F = F.toString();
	if (F.length > 9) {
		console.log("Future Value: $" + F.substring(0, (F.length - 9))
			+ "," + F.slice((F.length - 9), (F.length - 6)) + "," + F.slice(-6));
	}
	else if (F.length > 6) {
		console.log("Future Value: $" + F.substring(0, (F.length - 6))
			+ "," + F.slice(-6));
	}
	else
		console.log("Future Value: $" + F);
	console.log("============================")
}

// Calculate the future value of an account
function calculateFutureValue(P, i, t) {
	F = P * Math.pow(1 + i, t)
	return F;
}