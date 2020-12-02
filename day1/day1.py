with open('input', 'r') as expense_report:
    expenses = [ int(a.strip()) for a in expense_report.readlines() ]
    expenses = sorted(expenses)

for a in expenses:
    for b in expenses:
        for c in expenses:
            if a + b + c == 2020:
                print(f"{a} + {b} + {c} = 2020, {a} * {b} * {c} = {a * b * c}")
                exit()

                
