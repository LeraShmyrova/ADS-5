// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int operacii(char op) {
  int c = 0;
  if (op == '(') {
  c = 0;
  } else if (op == ')') {
  c = 1;
  } else if (op == '+') {
  c = 2;
  } else if (op == '-') {
  c = 2;
  } else if (op == '*') {
  c = 3;
  } else if (op == '/') {
  c = 3;
  } else if (op == ' ') {
  c = 4;
  } else {
  c = 5;
  }
  return c;
  }

int vichislenie(char op, int b, int a) {
  int res = 0;
  if (op == '+') {
  res = b + a;
  } else if (op == '-') {
  res = b - a;
  } else if (op == '*') {
  res = b * a;
  } else if ((op == '/') && (a != 0)) {
  res = b / a;
  } else {
  res = 0;
  }
  return res;
}

std::string infx2pstfx(std::string inf) {
  std::string peremenaya;
  TStack <char, 100> TS;
  int i = 0;
  for (int i = 0; i < inf.size(); i++) {
  if (operacii(inf[i]) == 5) {
  peremenaya.push_back(inf[i]);
  peremenaya.push_back(' ');
  } else {
  if (operacii(inf[i]) == 0) {
  TS.push(inf[i]);
  } else if (operacii(inf[i]) == 1) {
  while (operacii(TS.get()) != 0) {
  peremenaya.push_back(TS.get());
  peremenaya.push_back(' ');
  TS.pop();
  }
  TS.pop();
  } else if ((operacii(inf[i])) > (operacii(TS.get()))) {
  TS.push(inf[i]);
  } else if (TS.isEmpty()) {
  TS.push(inf[i]);
  } else {
  while ((!TS.isEmpty()) && ((operacii(inf[i])) <= (operacii(TS.get())))) {
  peremenaya.push_back(TS.get());
  peremenaya.push_back(' ');
  TS.pop();
  }
  TS.push(inf[i]);
  }
  }
  }
  while (!TS.isEmpty()) {
  peremenaya.push_back(TS.get());
  peremenaya.push_back(' ');
  TS.pop();
  }
  int j = 0;
  while (j < peremenaya.size()) {
  if (peremenaya[peremenaya.size() - 1] == ' ') {
  peremenaya.erase(peremenaya.size() - 1);
  }
  j++;
  }
  return peremenaya;
}

int eval(std::string pref) {
  int result = 0;
  TStack <int, 100> TSt;
  for (int i = 0; i < pref.size(); i++) {
  if (operacii(pref[i]) == 5) {
  TSt.push(pref[i] - '0');
  } else if (operacii(pref[i]) <= 3) {
  int b = TSt.get();
  TSt.pop();
  int a = TSt.get();
  TSt.pop();
  TSt.push(vichislenie(pref[i], b, a));
  }
  }
  result = TSt.get();
  return result;
}
