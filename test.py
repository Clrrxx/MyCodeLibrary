
def Align(n1, n2):
    for i in range(n1 + 1):
        Table[i, 0] = i

    for j in range(n2 + 1):
        Table[0, j] = j

    for i in range(1, n1+1):
        for j in range(1, n2+1):
            if s1[i-1] != s2[j-1]:
                Table[i, j] = min(Table[i, j-1] + 1, Table[i-1, j] + 1)
            else:
                Table[i, j] = Table[i-1, j-1]
    return Table[n1, n2]