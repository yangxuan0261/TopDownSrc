// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include <iostream>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <string>
#include <queue>

#define SPLIT_BY_FENHAO	";"
#define SPLIT_BY_DOUHAO	","
#define SPLIT_BY_XIAHUAXIAN	"_"
#define SPLIT_BY_JINGHAO	"#"

#define TCHAR_TO_ANSIANSI_TO_TCHAR(str) (TCHAR*)StringCast<TCHAR>(static_cast<const ANSICHAR*>(str)).Get()
#define TCHAR_TO_UTF8(str) (ANSICHAR*)FTCHARToUTF8((const TCHAR*)str).Get()
#define UTF8_TO_TCHAR(str) (TCHAR*)FUTF8ToTCHAR((const ANSICHAR*)str).Get()

/**
*
*/
class MYBTTEST_API CCommonHead
{
public:
	CCommonHead();
	~CCommonHead();
};