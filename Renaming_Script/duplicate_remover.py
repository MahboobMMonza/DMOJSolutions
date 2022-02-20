import json
import os


def distinguish(name: str, fastest: int):
    file_path = '../{}'
    files_list = os.listdir('..')
    duplicate_files = [i for i in files_list if i.startswith(name) and (i[len(name)] in '._')]
    for i, file in enumerate(duplicate_files):
        if os.path.exists(file_path.format(file)) and i + 1 != fastest:
            print('Deleting', file)
            os.remove(file_path.format(file))
    if fastest != 1 and os.path.exists(file_path.format(duplicate_files[fastest - 1])):
        print('Renaming', duplicate_files[fastest - 1], 'to', duplicate_files[0])
        os.rename(file_path.format(duplicate_files[fastest - 1]), file_path.format(duplicate_files[0]))


def dict_filter(subs: dict):
    problem_ids = {}
    for i, sub in enumerate(subs):
        problem_name = subs[sub]['problem']
        if problem_name in problem_ids:
            problem_ids[problem_name].append(sub)
        else:
            problem_ids[problem_name] = [sub]
    return {k: v for k, v in problem_ids.items() if len(v) > 1}


def main():
    submission_info = json.load(open('../info.json'))
    filtered_problems = dict_filter(submission_info)
    for problem in filtered_problems:
        fastest, fast_time = -1, 10000
        for i, sub_id in enumerate(filtered_problems[problem]):
            if submission_info[sub_id]['time'] < fast_time:
                fastest = i + 1
                fast_time = submission_info[sub_id]['time']
        distinguish(str(problem), fastest)
        print('Success')
    print('Renaming complete')


main()
