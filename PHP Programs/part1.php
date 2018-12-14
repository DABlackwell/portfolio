<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Trump's Cabinet</title>
    </head>
    <body>
        <?php
        $cabinet = array('President' => 'Trump',
            'Vice President' => 'Pence',
            'Secretary of State' => 'Tillerson',
            'Secretary of Treasury' => 'Mnuchin',
            'Secretary of Defense' => 'Mattis');
        asort($cabinet);
        echo '<h2>Trump Administration Cabinet Members</h2>' .
             '<h4>Sorted ascending by name</h4><ul>';
        foreach ($cabinet as $position => $name) {
            echo "<li>$position is $name</li>";
        }
        echo '</ul>';
        ksort($cabinet);
        echo '<h4>Sorted ascending by position</h4><ul>';
        foreach ($cabinet as $position => $name) {
            echo "<li>$position is $name</li>";
        }
        echo '</ul>';
        ?>
    </body>
</html>
