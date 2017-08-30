#!/usr/bin/python
# -*- coding: utf-8 -*-
# Submit Tool v 1.1
import urllib
import urllib.request
import urllib.parse
import sys
import json
import os
import time
from getpass import getpass

r = lambda: sys.stdin.readline()


def get_source(filename):
    if not os.path.exists(filename):
        return ({'error': True, 'error_text': u'%s는 없는 파일입니다' % filename}, '')
    fp = open(filename, 'r')
    source = fp.read()
    fp.close()
    return ({'error': False}, source)


def submit(username, password, problem_id, source, language):
    url = 'https://www.acmicpc.net/cmd/submit'
    values = {'username': username, 'password': password,
              'problem_id': problem_id, 'source': source,
              'language': language, 'version': '1.1'}
    user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.7) Gecko/2009021910 Firefox/3.0.7'
    hdr = {'User-Agent': user_agent}
    data = urllib.parse.urlencode(values)
    req = urllib.request.Request(url, data, hdr)
    response = urllib.request.urlopen(req)
    result = response.read()
    response.close()
    result = json.loads(result)
    return result


def get_result(solution_id, key):
    results = [u'기다리는 중', u'재채점을 기다리는 중',
               u'컴파일 하는 중', u'채점중', u'맞았습니다!!',
               u'출력 형식이 잘못되었습니다', u'틀렸습니다', u'시간 초과',
               u'메모리 초과', u'출력 초과', u'런타임 에러', u'컴파일 에러']
    print(u'채점 번호: %d' % solution_id)
    while True:
        url = 'https://www.acmicpc.net/cmd/status'
        values = {'solution_id': solution_id, 'key': key}
        user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.7) Gecko/2009021910 Firefox/3.0.7'
        hdr = {'User-Agent': user_agent}
        data = urllib.parse.urlencode(values)
        req = urllib.request.Request(url, data, hdr)
        response = urllib.request.urlopen(req)
        result = response.read()
        response.close()
        result = json.loads(result)
        if result['error']:
            print(result['error_text'])
            return
        ans = result['result']
        eval_result = int(ans['result'])
        if eval_result == 3:
            if 'progress' in result:
                print(u'%s (%s%%)' % (results[eval_result], result['progress']))
            else:
                print(u'%s' % (results[eval_result]))
        else:
            print(results[eval_result])
        if eval_result >= 4:
            if eval_result == 4:
                print(u'메모리: %(memory)s KB\n시간: %(time)s MS\n코드 길이: %(code_length)s B' % ans)
            else:
                print(u'코드 길이: %(code_length)s B' % ans)
            if eval_result == 10 or eval_result == 11:
                print(u'%s 메시지' % results[eval_result])
                print(result['error_text'])
            break
        time.sleep(1)


def get_problem_id_from_filename(filename):
    problem_id, extension = os.path.splitext(filename)
    if problem_id.isdigit():
        return int(problem_id)
    else:
        return -1


def main():
    argv = sys.argv[1:]
    if len(argv) < 3 or len(argv) > 4:
        print(u'사용법: python submit.py filename username password')
        print(u'사용법: python submit.py problem_id filename username password')
        return

    if len(argv) == 3:
        filename = argv[0]
        problem_id = get_problem_id_from_filename(filename)
        if problem_id == -1:
            print(u'파일 이름은 문제번호.확장자 형식이 되어야 합니다')
            return
        username = argv[1]
        password = argv[2]
    else:
        problem_id = int(argv[0])
        filename = argv[1]
        username = argv[2]
        password = argv[3]

    language = 1
    res, source = get_source(filename)
    if res['error']:
        print(res['error_text'])
        return

    res = submit(username, password, problem_id, source, language)
    if res['error']:
        print(res['error_text'])
        return
    if 'notice' in res:
        print(res['notice'])
    get_result(res['solution_id'], res['key'])


if __name__ == '__main__':
    main()
