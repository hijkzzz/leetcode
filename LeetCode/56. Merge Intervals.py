#coding: utf-8
from operator import itemgetter

def combine(sections):
    """区间合并
    时间复杂度O(nlogn), 空间复杂度O(1)
    """

    sections.sort(key=itemgetter(0))
    # print(sections)
    result = []

    start = sections[0][0]
    end = sections[0][1]
    for i in range(1, len(sections)):
        # 连续的时候合并
        if end >= sections[i][0]:
            end = max(sections[i][1], end)
        # 不连续的时候输出
        else:
            result.append((start, end))
            start, end = sections[i]

    result.append((start, end))
    return result


if __name__ == '__main__':
    sections = [(1, 2), (3, 4), (2, 5), (6, 7)]
    print(combine(sections))
