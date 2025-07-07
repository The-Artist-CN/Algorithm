def longestPalindrome(s: str) -> int:
    # 用字典统计每个字符的出现次数
    char_count = {}
    for char in s:
        char_count[char] = char_count.get(char, 0) + 1

    # 计算最长回文串的长度
    palindrome_length = 0
    odd_found = False
    for count in char_count.values():
        # 如果是偶数，全部加到回文长度
        if count % 2 == 0:
            palindrome_length += count
        else:
            # 如果是奇数，取偶数部分
            palindrome_length += count - 1
            odd_found = True

    # 如果有奇数个字符，可以放一个到中心
    if odd_found:
        palindrome_length += 1

    return palindrome_length

# 测试
s = "abccccdd"
print(longestPalindrome(s))  # 输出 7

