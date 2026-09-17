import os
import re

LEETCODE_PROFILE = "https://leetcode.com/u/Lucky_0704"
NEETCODE_PROFILE = "https://neetcode.io/user/MagneticObelisk925"

README_TEMPLATE = """# 🎯 LeetCode & NeetCode Solutions

Structured solutions, optimal approaches, and complexity analysis for technical interview preparation.

## 👤 Competitive Profiles
- **LeetCode:** [{lc_link}]({lc_link})
- **NeetCode:** [{nc_link}]({nc_link})

## 📊 Progress Dashboard
- **Total Problems Solved:** {total}
- **Topics Covered:** {topics_count}

## 📚 Problem Catalog

| # | Problem | LeetCode | NeetCode | Topic | Difficulty | Solution | Date |
|---|---------|:--------:|:--------:|-------|------------|----------|------|
{rows}

---
*Auto-updated via [GitHub Actions](.github/workflows/update_readme.yml).*
"""

problems = []

for root, dirs, files in os.walk("."):
    # Ignore the .git folder and scripts folder specifically
    if "/.git" in root or root.startswith("./.git") or "scripts" in root:
        continue

    for file in sorted(files):
        if file.endswith((".cpp", ".py", ".java")):
            filepath = os.path.join(root, file).replace("\\", "/")
            with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()

            name = re.search(r"Problem Name\s*:\s*(.*)", content)
            lc_id = re.search(r"LeetCode ID\s*:\s*(.*)", content)
            nc_id = re.search(r"NeetCode ID\s*:\s*(.*)", content)
            diff = re.search(r"Difficulty\s*:\s*(.*)", content)
            topic = re.search(r"Topic\s*:\s*(.*)", content)
            date = re.search(r"Date Solved\s*:\s*(.*)", content)

            p_name = name.group(1).strip() if name else file
            p_lc = lc_id.group(1).strip() if lc_id else "-"
            p_nc = nc_id.group(1).strip() if nc_id else "-"
            p_diff = diff.group(1).strip() if diff else "Easy"
            p_topic = topic.group(1).strip() if topic else "General"
            p_date = date.group(1).strip() if date else "-"

            lc_cell = f"[#{p_lc}](https://leetcode.com/problems/{p_nc}/)" if p_lc != "-" else "-"
            nc_cell = f"[{p_nc}](https://neetcode.io/problems/{p_nc})" if p_nc != "-" else "-"

            problems.append({
                "name": p_name,
                "lc_cell": lc_cell,
                "nc_cell": nc_cell,
                "topic": p_topic,
                "diff": p_diff,
                "link": f"[{file}]({filepath})",
                "date": p_date
            })

table_rows = []
unique_topics = {p["topic"] for p in problems}

for idx, p in enumerate(problems, 1):
    table_rows.append(
        f"| {idx} | {p['name']} | {p['lc_cell']} | {p['nc_cell']} | `{p['topic']}` | {p['diff']} | {p['link']} | {p['date']} |"
    )

with open("README.md", "w", encoding="utf-8") as f:
    f.write(README_TEMPLATE.format(
        lc_link=LEETCODE_PROFILE,
        nc_link=NEETCODE_PROFILE,
        total=len(problems),
        topics_count=len(unique_topics),
        rows="\n".join(table_rows) if table_rows else "| - | No problems added yet | - | - | - | - | - | - |"
    ))