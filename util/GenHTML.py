from sys import argv

import pathlib

C_SRC_PATH = "CSrc/"
ALGO_PATH = "Algo/"
OUTPUT_DIR = "Printable/"

def GetFileContent(path: str) -> str:
    with open(path, "r") as file:
        return file.read()
    
def GetFilePairs(FileListPath: str) -> list[tuple[str, str]]:
    filePair: list[tuple[str, str]] = list()
    with open(FileListPath, "r") as fileList:
        
        component = fileList.readline().strip()
        while(component != ""):
            filePair.append((f"{ALGO_PATH}{component}.htm", f"{C_SRC_PATH}{component}.c"))
            component = fileList.readline().strip()

    return filePair

def GetFileList(FileListPath: str) -> list[str]:
    with open(FileListPath, "r") as file:
        fileList = file.read().splitlines()

    return fileList

def ExtractHTMLLines(htmlFilePath: str) -> list[str]:
    with open (htmlFilePath, "r") as HTMLFile:
        rawSrc = HTMLFile.read()
        lines = rawSrc.splitlines()
        for i in range(len(lines)):
            lines[i] = lines[i].strip()
        fmtSrcLines: list[str] = list()
        for line in lines:
            if line.find('<li>') != -1:
                fmtSrcLines.append(line.replace("<li>", "").replace("</li>", ""))

        return fmtSrcLines

def ExtractCCodeLines(srcFilePath: str) -> list[str]:
    with open(srcFilePath, "r") as CSrcFile:
        rawCSrcCode = CSrcFile.read().replace("\t", "&nbsp;&nbsp;&nbsp;&nbsp;").replace("    ", "&nbsp;&nbsp;&nbsp;&nbsp;").replace("<", "&lt;")
    return rawCSrcCode.splitlines()

def GenHTMLSrc(fileNameNoExt: str) -> tuple[str, str]:
    algoLines = ExtractHTMLLines(f"{ALGO_PATH}{fileNameNoExt}.htm")
    CSrcLines = ExtractCCodeLines(f"{C_SRC_PATH}{fileNameNoExt}.c")



    algoStringFmt = ""
    for line in algoLines:
        algoStringFmt = algoStringFmt + f"<li>{line}</li>\n"
    

    CSrcStringFmt = ""
    for line in CSrcLines:
        CSrcStringFmt = CSrcStringFmt + f"<li>{line}</li>\n"


        HTMLSrcTheory = \
f"""
<html>
        <head>
            <title> to be filled later </title>  
            <link rel="stylesheet" type="text/css" href="Assignment-Style.css">
        </head>

        <body>
            AIM: 
            <br>

            THEORY:

            <br>
            ALGORITHM: <br> <br>
            <ol>
                {algoStringFmt}
            </ol>
        </body>
</html>
    """
    HTMLSrcC = \
f"""
<html>
        <head>
            <title> to be filled later </title>  
            <link rel="stylesheet" type="text/css" href="Assignment-Style.css">
        </head>

        <body>
        C PROGRAM: <br> <br>
        <ol>
            {CSrcStringFmt}
        </ol>
        </body>
</html>


"""

    return HTMLSrcTheory, HTMLSrcC

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

        theoryHTMLSrc, CHTMLSrc = GenHTMLSrc(fileNameNoExt)
        with open(f"{OUTPUT_DIR}Theory/{fileNameNoExt}HTMLTheory.htm", "w") as HTMLTheory:
            HTMLTheory.write(theoryHTMLSrc)

        with open(f"{OUTPUT_DIR}C/{fileNameNoExt}HTMLCSrc.htm", "w") as HTMLCSrc:
            HTMLCSrc.write(CHTMLSrc)

    
    theoryLinks = ""

    theoryDir = pathlib.Path(f"{OUTPUT_DIR}/Theory")
    for pathObject in theoryDir.glob("*"):
        if not pathObject.is_file() or pathObject.suffix != ".htm": continue
        path = str(pathObject.relative_to(OUTPUT_DIR))
        theoryLinks = theoryLinks + f"<a href={path}> {path} </a> <br>\n"

    CSrcLinks = ""

    CDir = pathlib.Path(f"{OUTPUT_DIR}/C")
    for pathObject in CDir.glob("*"):
        if not pathObject.is_file() or pathObject.suffix != ".htm": continue
        path = str(pathObject.relative_to(OUTPUT_DIR))
        CSrcLinks = CSrcLinks + f"<a href={path}> {path} </a> <br>\n"

    mainHTMLSrc = \
    f"""
<html>

    <head>
        <title>2<sup>nd</sup> Sem Practical</title>
        <link rel="stylesheet" type="text/css" href="Assignment-Style.css">
    </head>

    <body>
        Theroy Section: <br>

        {theoryLinks}

        <br> <br>
        
        C Source Code: <br>

        {CSrcLinks}
    </body>
    
"""
    with open(f"{OUTPUT_DIR}main.html", "w") as mainHTML:
        mainHTML.write(mainHTMLSrc)

if __name__=="__main__":
    main()
