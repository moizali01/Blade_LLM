from bs4 import BeautifulSoup

def get_html_file(filename):
    with open(filename, 'r') as f:
        return f.read()

def get_covered_code(html, type_coverage='covered-line'):
    soup = BeautifulSoup(html, 'html.parser')
    data = []
    lines = (soup.find_all('tr'))
    for line in lines:
        covered_line = line.find('td', class_=type_coverage)
        if (covered_line is None):
            continue
        if (type_coverage == 'uncovered-line'):
            code = line.find('td', class_='code').find('pre').text
            data.append(code)

        else:
            cov = covered_line.find('pre').text
            if (int(cov) > 0):
                code = line.find('td', class_='code').find('pre').text
                data.append(code)

    return data

def write_to_file(data, filename):
    with open(filename, 'w') as f:
        f.write('\n'.join(data))

def __main__():
    content = get_html_file('original.html')
    # uncovered lines will give the lines with 0 or non executed lines
    data = get_covered_code(content, 'covered-line') #covered-line or uncovered-line
    write_to_file(data, 'covered_code.c')

__main__()