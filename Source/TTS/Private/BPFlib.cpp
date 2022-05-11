// Fill out your copyright notice in the Description page of Project Settings.


#include "BPFlib.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"
#include <sapi.h>
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"

static ISpVoice* pVoice; //初始化COM 

static HRESULT hr;


void UBPFlib::Start()
{
	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
}

void UBPFlib::Quit()
{
	if (pVoice != NULL)
	{
		pVoice->Release();
		pVoice = NULL;
		CoUninitialize();

	}
}

void UBPFlib::Speak(const FString & Str)
{
	pVoice = NULL;
	if (FAILED(CoInitialize(NULL)))
	{
		/*AfxMessageBox(_T("Error to intiliaze COM"));*/
		return;
	}
	// 初始化SAPI   
	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	ISpObjectToken* pSpObjectToken = NULL;
	/*if (SUCCEEDED(SpFindBestToken(SPCAT_VOICES, _T("language=804"), NULL, &pSpObjectToken)))// 804代表中文   
	//if (SUCCEEDED(hr))   
		{
		pVoice->SetVoice(pSpObjectToken); // 声音大小  
		pVoice->SetRate(0);// 语速  
		/*pVoice->Skip();#1#
		pSpObjectToken->Release();
		
		}
	else
	{
		/*AfxMessageBox(_T("没有安装微软语音库!"));#1#
		return;
	}*/
	if (SUCCEEDED(hr))
	{
		const TCHAR *t = TEXT("fdgfd");
		t = *Str;
		hr = pVoice->Speak(t, SPF_ASYNC, NULL);	
	}
}