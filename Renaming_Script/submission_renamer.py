import json
import os


def file_rename(path: str, name: str, frequency: int):
    file_path = '../{}'
    files_list = os.listdir('..')
    file_to_rename = file_path.format([i for i in files_list if path in i][0])
    new_name = file_to_rename.replace(path, name)
    if frequency > 1:
        new_name = file_to_rename.replace(path, name + '_' + str(frequency))
    if os.path.exists(file_to_rename) and not os.path.exists(new_name):
        os.rename(file_to_rename, new_name)
    else:
        print(f"Error trying to rename {path} to {new_name}")


def main():
    submission_info = json.load(open('../info.json'))
    # In case of duplicates
    freq = {}
    for i, submission in enumerate(submission_info):
        problem_name = submission_info[submission]['problem']
        if problem_name in freq:
            freq[problem_name] += 1
        else:
            freq[problem_name] = 1
        file_rename(submission, problem_name, freq[problem_name])


main()
