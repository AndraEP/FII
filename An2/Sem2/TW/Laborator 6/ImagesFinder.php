<?php

class ImagesFinder
{
    public static function findLocalImages(string $path)
    {
        return glob($path . "*.jpg");
    }
}

?>