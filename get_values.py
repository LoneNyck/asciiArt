from PIL import Image as im

class Pixel():
    def __init__(self, span: tuple, sym):
        self.span = span
        self.sym = sym

image = im.open("image.jpeg").convert("L")

width, height = image._size

pixels = list(image.getdata())

pixel_matrix = [[pixels[width * i + j] for j in range(width)] for i in range(height)]

with open("file.txt", "w") as f:
    f.write(f"{width} {height}\n")
    for line in pixel_matrix:
        for pixel in line:
            f.write(f"{str(pixel)} ")
        f.write("\n")
        
print(f"Matrix successfully created. Width {width} px, height {height} px.")
