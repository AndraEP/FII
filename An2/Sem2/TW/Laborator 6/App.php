<?php

require "HtmlOutput.php";
require "ImagesFinder.php";

class App
{
    public function run(string $path)
    {
        /*
        $finder = new ImagesFinder();
        $out = new HtmlOutput();
        $out->showImages($finder->findLocalImages($path));
        */
        HtmlOutput::showImages(ImagesFinder::findLocalImages($path));
    }
}

?>