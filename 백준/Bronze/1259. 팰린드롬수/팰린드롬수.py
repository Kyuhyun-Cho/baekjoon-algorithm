while(True):
    n = input()
    if n == '0':
        break
    else:
        n_list = list(n)
        reverse_n_list = list(n)
        reverse_n_list.reverse()
        
        if (n_list == reverse_n_list):
            print("yes")
        else:
            print("no")
