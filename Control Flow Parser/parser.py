__author__ = 'peace'


def parse():

    infile = open("source.c", "r")
    print(outerIfAndBody(infile.readlines()))

def recurse(lines):
    paths = outerIfAndBody(lines)
    for path in paths:
        for index, body in path:
            if len(body ) != 0:
                path[index] = outerIfAndBody(body)
                recurse(body)

def outerIfAndBody(lines):

    searchStr = ''
    gameOn = False
    curIndex = 0
    length = len(lines)
    huntingElse = False
    nodeCount = 0
    paths = []
    sibling = []
    topIfCount = 0
    comingFrom = 0
    linesToAppend = []

    for i in range(length):
        line = lines[i].strip()
        if (not gameOn) and str(line).strip().startswith("if"):
            gameOn = True
            topIfCount = nodeCount + 1
        if gameOn:
            searchStr += line
            linesToAppend.append(line)
            if huntingElse:

                if i == length - 1:
                    appendSibling(comingFrom, sibling, topIfCount, nodeCount, linesToAppend[1:-2], end=True)

                if searchStr.startswith('else if'):
                    appendSibling(comingFrom, sibling, topIfCount, nodeCount, linesToAppend[1:-2])
                    comingFrom = 1
                    huntingElse = False
                    linesToAppend = []
                elif searchStr.startswith('else'):
                    appendSibling(comingFrom, sibling, topIfCount, nodeCount, linesToAppend[1:-2])
                    huntingElse = False
                    comingFrom = 2
                    linesToAppend = []
                elif searchStr.startswith('if'):
                    appendSibling(comingFrom, sibling, topIfCount, nodeCount, linesToAppend[1:-2], end=True)
                    huntingElse = False
                    paths.append(sibling)
                    sibling = []
                    comingFrom = 0
                    topIfCount = nodeCount
                    linesToAppend = []

                else:
                    continue

            # find the index of }
            if str(searchStr).find('}', curIndex, len(searchStr)+1) != -1:
                curIndex = str(searchStr).find('}', curIndex, len(searchStr)+1)+1
                leftCount = str(searchStr)[:curIndex].count('}')
                rightCount = str(searchStr)[:curIndex].count('{')
                if leftCount != 0 and leftCount == rightCount:
                    # we have found the end of the if
                    # bodyToAppend = searchStr[startIndex+1:curIndex-1]
                    searchStr = searchStr[curIndex:].strip()
                    curIndex = 0
                    huntingElse = True
                    nodeCount += 1

    # add the final sibling
    if sibling is not []:
        paths.append(sibling)

    return paths

def appendSibling(comingFrom, sibling, topIfCount, nodeCount, linesToAppend, end=False):
    index = ''
    yeah = False
    for line in linesToAppend:
        if str(line).startswith('if'):
            yeah = True
    linesToAppend = linesToAppend if yeah else []
    if comingFrom == 0:
        index = str(nodeCount)+'T'
        sibling.append({index: linesToAppend})
        if end :
            index = str(nodeCount)+'F'
            sibling.append({index: []})
    elif comingFrom == 1:
        for j in range(topIfCount, nodeCount):
            index += str(j)+'F'
        index += str(nodeCount)+'T'
        sibling.append({index: linesToAppend})
        if end:
            index = ''
            for j in range(topIfCount, nodeCount+1):
                index += str(j)+'F'
            sibling.append({index: []})
    elif comingFrom == 2:
        for j in range(topIfCount, nodeCount):
            index += str(j)+'F'
        sibling.append({index: linesToAppend})
            
parse()
