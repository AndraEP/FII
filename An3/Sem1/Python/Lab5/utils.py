def process_item(x):
    copy = x
    if copy + 1 == 2:
        return copy + 1
    found = 0
    while found == 0:
        copy += 1
        for i in range(2, copy//2 + 2):
            if copy % i == 0:
                found = 0
                break
            else:
                found = 1
    return copy