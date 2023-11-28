import requests;

# url = 'http://161.246.5.61:11558/students/html/'
# reponse = requests.get(url)

# if reponse.status_code == 200:
#     print('Request successful!')
#     print('Response:', reponse.text)
# else:
#     print('Requset failed. Status code', reponse.status_code)


def post_pram(name, surname, id):
    url = "http://161.246.5.61:11558/students/newForm?student_name={}&student_surname={}&student_id={}".format(name, surname, id)
    response = requests.post(url)
    if response.status_code == 200:
        print(response.text)
    else:
        print("Error: ", response.status_code)


def post_link(name, surname, id):
    url = "http://161.246.5.61:11558/students/new/{}/{}/{}/".format(name, surname, id)
    response = requests.post(url)
    if response.status_code == 200:
        print(response.text)
    else:
        print('Request failed!. Status code:', response.status_code)
    

def post_json(name, surname, id):
    url = "http://161.246.5.61:11558/students/new/"
    response = requests.post(url, json={"name": name, "surname": surname, "ID": id})
    
    if response.status_code == 200:
        print(response.text)
    else:
        print("Error: ", response.status_code)


def get_each(id):
    url = 'http://161.246.5.61:11558/students/html/' + str(id)
    response = requests.get(url)
    if response.status_code == 200:
        print('Request successful!')
        print('Response:', response.text)
    else:
        print('Request failed!. Status code:', response.status_code)

def get_all():
    url = 'http://161.246.5.61:11558/students/html/'
    response = requests.get(url)
    if response.status_code == 200:
        print('Request successful!')
        print('Response:', response.text)
    else:
        print('Request failed!. Status code:', response.status_code)

#post_pram('test', 'ter', 1111)
#post_link('test', 'ter', 1111)
#post_json('test', 'ter', 1111)
#get_each(1111)
get_all()