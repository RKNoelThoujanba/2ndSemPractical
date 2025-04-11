from GenHTML import *
from sys import argv

def main():
    if(len(argv) != 2):
        print("File List not supplied!")
        return
    files = GetFilePairs(argv[1])
    print(f"Ruunning {argv[0]}...\nInput files from {argv[1]}:")
    for file in files:
        print(f"{file}")
    print()

    
    fileList = GetFileList(argv[1])

    for fileNameNoExt in fileList:

        _, CHTMLSrc = GenHTMLSrc(fileNameNoExt)

        with open(f"{OUTPUT_DIR}C/{fileNameNoExt}HTMLCSrc.htm", "w") as HTMLCSrc:
            HTMLCSrc.write(CHTMLSrc)

    
    theoryLinks = ""

    CSrcLinks = ""

    CDir = pathlib.Path(f"{OUTPUT_DIR}/C")
    for pathObject in CDir.glob("*"):
        if not pathObject.is_file() or pathObject.suffix != ".htm": continue
        path = str(pathObject.relative_to(OUTPUT_DIR))
        CSrcLinks = CSrcLinks + f"<a href={path}> {path} </a> <br>\n"

if __name__ == "__main__":
    main()