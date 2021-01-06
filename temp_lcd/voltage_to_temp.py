# voltage_to_temp.py
# translates from milivolts to Fahrenheit

import sys


def v2f(mv):
    mv = float(mv)
    temp_c = 100 * (mv - 500) / 1024
    temp_f = (temp_c * 9 / 5) + 32
    print(f"{mv}mv --> {round(temp_f, 1)}")


if __name__ == "__main__":
    if len(sys.argv) > 1:
        v2f(sys.argv[1])
    else:
        # give a rough idea of numbers
        v2f(691)
        v2f(526)
