import os
import re
import json
import requests
url = None
OJ = None
headers = {
    "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Mobile Safari/537.36",
}

info_template = '''{
    "type": "problem",
    "ID": "%s",
    "title": "%s",
    "OJ": "%s",
    "url": "%s",
    "tag": [
        "暴力"
    ],
    "level": [
        "入门"
    ],
    "description": {
        "type": "file",
        "file": "description.md"
    },
    "sample": [
    ],
    "code": [
        {
            "type": "file",
            "language": "c++",
            "file": "cpp_1.cpp"
        }
    ]
}
'''

def processLuogu():
    # 样例：https://www.luogu.com.cn/problem/P1000
    problemID = None
    title = None

    match = re.search(r"problem/(P[0-9]*)", url)
    if match != None:
        problemID = match.group(1) # P1000
    else:
        print("网址有误，找不到题目编号")
        return
    resp = requests.get(url, headers=headers)
    text = resp.text
    resp.close()
    match = re.search(r"<article>[\s\S]*?<h1>(.*?)</h1>", text)
    if match != None:
        title = match.group(1) # 超级玛丽游戏
    else:
        print ("没有解析到标题")
        return
    infoStr = info_template % (problemID, title, OJ, url)
    target_path = os.path.join(OJ, problemID)
    if not os.path.exists(target_path):
        os.makedirs(target_path)
    else:
        print ("题目模板已经创建过了")
        return
    with open(os.path.join(target_path, "cpp_1.cpp"), 'w', encoding='utf-8') as f:
        pass
    with open(os.path.join(target_path, "description.md"), 'w', encoding='utf-8') as f:
        pass
    with open(os.path.join(target_path, "info.json"), 'w', encoding='utf-8') as f:
        f.write(infoStr)
    print ("创建成功")

def processCodeforces():
    pass

onlineJudgeProcess = {
    "luogu": processLuogu,
    "codeforces": processCodeforces,
}

if __name__ == '__main__':
    print ("粘贴题目链接:")
    url = input()
    for ojName, processFunc in onlineJudgeProcess.items():
        if ojName in url:
            OJ = ojName
            processFunc()
            break
    if OJ == None:
        print("不支持此oj")