# #!/bin/bash

# export PATH=/usr/bin:/bin:/usr/local/bin

# REPO_PATH="/home/chinu/leetcode"
# BATCH_SIZE=4

# cd "$REPO_PATH" || exit

# FILES=$(git ls-files --others --exclude-standard | head -n $BATCH_SIZE)

# if [ -z "$FILES" ]; then
#     echo "No more files to commit."
#     exit 0
# fi

# git add $FILES

# if git diff --cached --quiet; then
#     echo "Nothing staged."
#     exit 0
# fi

# git commit -m "Add 4 LeetCode solutions"
# git push origin master

#!/bin/bash

export PATH=/usr/bin:/bin:/usr/local/bin

REPO_PATH="/home/chinu/leetcode"
BATCH_SIZE=4
BRANCH="master"   # change to main if needed

cd "$REPO_PATH" || exit

echo "Cron run at $(date)" >> /home/chinu/cron_leetcode.log

# Always sync with remote first (safe pull)
git pull --rebase origin $BRANCH >> /home/chinu/cron_leetcode.log 2>&1

FILES=$(git ls-files --others --exclude-standard | head -n $BATCH_SIZE)

if [ -z "$FILES" ]; then
    echo "No more files to commit." >> /home/chinu/cron_leetcode.log
    exit 0
fi

git add $FILES

if git diff --cached --quiet; then
    echo "Nothing staged." >> /home/chinu/cron_leetcode.log
    exit 0
fi

git commit -m "Add 4 LeetCode solutions" >> /home/chinu/cron_leetcode.log 2>&1

git push origin $BRANCH >> /home/chinu/cron_leetcode.log 2>&1