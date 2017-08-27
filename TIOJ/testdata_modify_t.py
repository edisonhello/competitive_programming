"""TIOJ AUTO MODIFY Testdata Script"""

from __future__ import absolute_import
from __future__ import print_function
from __future__ import unicode_literals

import requests
import random
import string
from bs4 import BeautifulSoup

# config

problem_id = '1995' # problem id
num_start = 0 # testdata No. range, []
num_end = 7
upload_input = False # if you want to update the testdata files
upload_output = False
input_suffix = '.in'
output_suffix = '.out'
input_prefix = ''
output_prefix = ''
filename_format = '%s%02d%s' # % (prefix, id, suffix)
time_limit = '900'
memory_limit = '23040'

TIOJusername = "" #enter your TIOJ username
TIOJpassword = "" #enter your TIOJ password

# end config

url = 'http://tioj.ck.tp.edu.tw/problems/%s/testdata' % problem_id
   
session = requests.Session()

def login():
    print('logging in...')
    global session
    rel = session.get('http://tioj.ck.tp.edu.tw/users/sign_in')
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    data = {
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        'user[username]': TIOJusername,
        'user[password]': TIOJpassword,
        'user[remember_me]': '1',
        'commit': 'Sign in'
    }
    rel = session.post('http://tioj.ck.tp.edu.tw/users/sign_in', data=data)

login()

rel = session.get(url)
soup = BeautifulSoup(rel.text, "html.parser")
inputs = soup.find_all('a')

lst = []
for t in inputs:
    st = str(t)
    if st.find("btn btn-info btn-xs") != -1:
        c = st.find("testdata") + 9
        d = st.find("/", c)
        val = int(st[c:d])
        if not val in lst: lst.append(val)
lst = lst[num_start:num_end+1]

if len(lst) == 0: print('Error')

c = num_start
for i in lst:
    print('processing %d(%d)...' % (c, i))
    now_url = 'http://tioj.ck.tp.edu.tw/problems/%s/testdata/%d/edit' % (problem_id, i)
    post_url = now_url[:-5]
    
    rel = session.get(now_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    data = {
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'testdatum[limit_attributes][time]': time_limit,
        'testdatum[limit_attributes][memory]': memory_limit,
        'testdatum[limit_attributes][output]': '65536',
        'testdatum[limit_attributes][id]': str(i),
        'testdatum[problem_id]': problem_id,
        'commit': 'Update Testdatum'
    }
    
    files = {}
    if upload_input: files['testdatum[test_input]'] = open(filename_format % (input_prefix, c, input_suffix), 'rb')
    if upload_output: files['testdatum[test_output]'] = open(filename_format % (output_prefix, c, output_suffix), 'rb')
    rel = session.post(post_url, data = data, files = files)

    print('Modify %d(%d)!!' % (c, i))
    c += 1
