import os

allfiles = os.listdir(".")

cppfiles = [file for file in allfiles if file.endswith(".cpp")]

def get_index(file):
    return int(file.split(".")[0].split(" ")[0])


cppfiles.sort(key=get_index)

readme = open("README.md", "w")

title = """
# LeetCode Solutions
---

## Table of Contents

"""

readme.write(title)

for i in cppfiles:
    path = i.replace(" ", "%20")
    line = f"- [{i[:-4]}](./{path})\n"
    readme.write(line)


readme.close()
