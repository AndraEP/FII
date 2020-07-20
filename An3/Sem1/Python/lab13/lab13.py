import os
import zipfile

#ex1
def ex1(a_path, ext, zip_path):
    if os.path.isdir(a_path):
        for file in os.walk(a_path):
            extention = os.path.splitext(file)[-1].lower()
            if extention == ext:
                zip_file = zipfile.ZipFile(zip_path, 'w')
                zip_file.write(file)
        zip_file.close()
ex1('D:\\Work\\Python\\lab13', '.jpg', 'D:\\Work\\Python\\lab13\\file.zip')

#ex2
def ex2(a_path):
    if zipfile.is_zipfile(a_path):
        zip_file = zipfile.ZipFile(a_path, 'r')
        for file in zip_file.namelist():
            print(file)
        zip_file.close()
    else:
        return False
ex2('D:\\Work\\Python\\lab13\\file.zip')