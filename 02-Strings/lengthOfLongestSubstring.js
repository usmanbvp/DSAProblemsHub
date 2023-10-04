//Given a string s, find the length of the longest substring without repeating characters.
function lengthOfLongestSubstring(s) {
  let substring = "";
  let maxValue = 0;
  let left = 0,
    right = 1;

  while (right <= s.length) {
    substring = s.slice(left, right);
    if (maxValue < substring.length) maxValue = substring.length;
    if (substring.includes(s[right])) {
      left++;
    } else {
      right++;
    }
  }

  return maxValue;
};