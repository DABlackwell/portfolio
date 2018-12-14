<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Random Integer Count</title>
    </head>
    <body>
        <?php
        $random_nums = array();
        $array_size = 25;
        for ($i = 0; $i < $array_size; $i++) {
            $random_nums[$i] = mt_rand(1, 10);
        }
        sort($random_nums);
        foreach ($random_nums as $n) {
            echo $n . ' ';
        }
        echo '<br>Total of all elements = ' . array_sum($random_nums) . '<br>';
        $occurrences = array_count_values($random_nums);
        foreach ($occurrences as $k => $v) {
            if ($v == 1) {
                $s = '';
            } else {
                $s = 's';
            }
            echo "$k occurred $v time$s.<br>";
        }
        ?>
    </body>
</html>
