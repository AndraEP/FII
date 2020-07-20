import sqlite3
import os
import zipfile
from os.path import join

def problema1 (path, low, high):
    result = []
    if zipfile.is_zipfile(path):
        result.append(find_result(path, low, high))
        return result
    for root, dirs, files in os.walk(path):
        for file in files:
            if hasSearch(join(root, file)):
                path = join(root, file)
                result.append(find_result(path, low, high))
                return result

def hasSearch(path):
    if zipfile.is_zipfile(path):
        return True

def find_result(path, low, high):
    result = []
    zip_file = zipfile.ZipFile(path, 'r')
    for file_is in zip_file.namelist():
        if file_is == "sample.sqlite":
            zip_file.extract(file_is, original_path)
            string = original_path + "/" +file_is
            conn = sqlite3.connect(string)
            c = conn.cursor()
            c.execute("SELECT Title FROM albums")
            titles = c.fetchall()
            for title in titles:
                c.execute(
                    "SELECT tracks.Name FROM tracks INNER JOIN albums ON tracks.AlbumId = albums.AlbumId WHERE albums.title = ? AND tracks.Milliseconds <= ? AND tracks.Milliseconds >= ?",
                    (title[0], high, low))
                track_names = c.fetchall()
                for track_name in track_names:
                    c.execute(
                        "SELECT genres.Name FROM genres INNER JOIN tracks ON tracks.GenreId = genres.GenreId WHERE tracks.Name = ?",
                        (track_name[0],))
                    genres = c.fetchall()
                    for genre in genres:
                        result.append(tuple([title, track_name, genre[0]]))
            conn.close()
    zip_file.close()
    return result

original_path = "data/test1"
print(problema1(original_path, 330000, 330200))