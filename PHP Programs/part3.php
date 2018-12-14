<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>NFL Team Players</title>
    </head>
    <body>
        <?php
        echo '<h2>Some NFL Team Players</h2>';
        $nfl['Bucs'] =
                array('QB' => 'Winston',
                      'DT' => 'McCoy',
                      'RB' => 'Martin',
                      'WR' => 'Evans');
        $nfl['Packers'] =
                array('QB' => 'Rodgers',
                      'WR' => 'Nelson',
                      'LG' => 'Sitton',
                      'OLB' => 'Matthews',);
        $nfl['Patriots'] =
                array('QB' => 'Brady',
                      'TE' => 'Gronkowski',
                      'LB' => 'Collins',
                      'CB' => 'Butler',);
        foreach ($nfl as $team => $players) {
            echo "<h3>$team</h3>";
            foreach ($players as $position => $name) {
               echo "<li>$position: $name</li>";
            }
        }
        ?>
    </body>
</html>
