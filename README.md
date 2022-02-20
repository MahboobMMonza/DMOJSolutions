# DMOJ Solutions

This is a repository for all of my current DMOJ problem solutions to
date, under the username 
[*saleemShady*](https://dmoj.ca/user/saleemShady). Refer to 
[Finding a Problem Solution](#finding-a-problem-solution) under
**Navigation** for more info on how to find the solution to a 
specific problem. The repository also includes Python scripts
for any DMOJ users looking to export their data and create
a repository to store their solutions to all their solved problems.

## Languages

Most solutions are in C++, while some may exist in Java and Python.

## Navigation

### Finding a Problem Solution
In order to find a solution to a specific problem, check the problem
name at the end of the url for the link to that problem in DMOJ
(e.g. *CCC '15 S4 - Convex Hull* would have the 
URL: https://dmoj.ca/problem/ccc15s4, in which the problem name would
be found after the last '/', making it *ccc15s4*). Look for the file
name corresponding to this problem name in [Solutions](\Solutions).

### File Renaming Scripts
Submission data exported from DMOJ tends to have submission file
names stored as IDs, with a JSON file called *info.json*; this
info.json file contains submission details for each file, corresponding
to their submission IDs, and can be used to distinguish which problems
were solved based on the ID. The Python scripts found in
[Renaming_Script](/Renaming_Script) can be used to rename files so
that the problems are more recognizable. The script
[submission_renamer.py](/Renaming_Script/submission_renamer.py)
renames all files and accounts for duplicate solutions, while
[duplicate_remover.py](/Renaming_Script/duplicate_remover.py) removes
all duplicates and keeps only the solution with the fastest time.