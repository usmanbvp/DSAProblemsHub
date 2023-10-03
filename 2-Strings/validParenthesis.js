//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

function isValid(s) {

  const bracketsMap = {
    ')': '(',
    ']': '[',
    '}': '{'
  };

  let openBracketsStack = [];

  for (let i = 0; i < s.length; i++) {
    const currentBracket = s[i];

    if (['(', '[', '{'].includes(currentBracket)) {
      openBracketsStack.push(currentBracket);
    } else if (openBracketsStack.pop() !== bracketsMap[currentBracket]) {
      return false;
    }
  }
  return !openBracketsStack.length;
};