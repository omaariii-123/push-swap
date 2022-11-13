
import sys, random, os

def test(start, end):
    lst = list(range(start, end+1))

    random.shuffle(lst)

    arg=""
    for i in lst:
        arg += f"{i} "
    os.system(f"./push_swap {arg} | ./checker_linux {arg}")
    os.system(f"./push_swap {arg} | wc -l")

def main():

    if (len(sys.argv) != 3):
        print("hello")
        return (-42)
    start = int(sys.argv[1])
    end = int(sys.argv[2])
    print(start, end)

    for i in range(0, 100):
        test(start, end)

main()
