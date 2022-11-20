result = []
for i in range(1, 3):
    us = ''
    them = ''
    with open(f'tests/0{i}.out','w') as f:
        us = f.read()
    with open(f'tests/0{i}_sol.out','w') as f:
        them = f.read()
    result.append((us,them,us==them))

