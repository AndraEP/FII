<?php

class HtmlOutput
{
    public static function showImages(array $imagesPaths)
    {
        foreach($imagesPaths as $image)
        {
            echo "<img src=\"" . $image . "\">";
        }
    }
}

?>