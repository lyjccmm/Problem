import os
import json

all_tags = {}
all_levels = {}
for root, dirs, files in os.walk("."):
    for name in files:
        if name == "info.json":
            data = None
            with open(os.path.join(root, name), 'r', encoding='utf-8') as f:
                data = json.loads(f.read())
            tags = data.get("tag", [])
            levels = data.get("level", [])
            for i in tags:
                all_tags[i] = 1
            for i in levels:
                all_levels[i] = 1
print()
print(list(all_tags.keys()))
print()
print(list(all_levels.keys()))
print()