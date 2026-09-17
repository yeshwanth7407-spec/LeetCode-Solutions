import os
import re

LEETCODE_PROFILE = "https://leetcode.com/u/yeshwanth7407/"
NEETCODE_PROFILE = "https://neetcode.io/"

README_TEMPLATE = """# 🎯 LeetCode & NeetCode Solutions

Structured solutions, optimal approaches, and complexity analysis for technical interview preparation.

## 👤 Competitive Profiles
- **LeetCode:** [{lc_link}]({lc_link})
- **NeetCode:** [{nc_link}]({nc_link})

## 📊 Progress Dashboard
- **Total Problems Solved:** {total}
- **Topics Covered:** {topics_count}

## 📚 Problem Catalog

| # | Problem | Topic | Difficulty | Solution | Date |
|---|---------|-------|------------|----------|------|
{rows}

---
*Auto-updated via [GitHub Actions](.github/workflows/update_readme.yml).*
"""

problems = []

for root, dirs, files in os.walk("."):
    if any(part.startswith(".") for part in root.split(os.sep)) or "scripts" in root:
        continue

    for file in sorted(files):
        if file.endswith((".cpp", ".py", ".java")):
            filepath = os.path.join(root, file).replace("\\", "/")
            with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()

            name = re.search(r"Problem Name\s*:\s*(.*)", content)
            diff = re.search(r"Difficulty\s*:\s*(.*)", content)
            topic = re.search(r"Topic\s*:\s*(.*)", content)
            date = re.search(r"Date Solved\s*:\s*(.*)", content)

            problems.append({
                "name": name.group(1).strip() if name else file,
                "diff": diff.group(1).strip() if diff else "Medium",
                "topic": topic.group(1).strip() if topic else "General",
                "link": f"[{file}]({filepath})",
                "date": date.group(1).strip() if date else "-"
            })

table_rows = []
unique_topics = {p["topic"] for p in problems}

for idx, p in enumerate(problems, 1):
    table_rows.append(f"| {idx} | {p['name']} | `{p['topic']}` | {p['diff']} | {p['link']} | {p['date']} |")

with open("README.md", "w", encoding="utf-8") as f:
    f.write(README_TEMPLATE.format(
        lc_link=LEETCODE_PROFILE,
        nc_link=NEETCODE_PROFILE,
        total=len(problems),
        topics_count=len(unique_topics),
        rows="\n".join(table_rows) if table_rows else "| - | No problems added yet | - | - | - | - |"
    ))