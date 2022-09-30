# Cobalt Strike BOF - patchit (Both syscalls and dynamic resolve versions are available)

An all-in-one BOF to patch, check and revert AMSI and ETW for x64 process. Wrote this to avoid redundant AMSI / ETW patch.

Currently, it only checks the first 10+ bytes of AmsiScanBuffer and EtwEventWrite, since most of public available patch bytes are doing on first few lines. If thats not enough, additional bytes / function to compare can be added easily to the source code.

If you are not using the AMSI/ETW patch from this BOF and want to revert, you could refresh the whole AMSI and NTDLL as an alternative.

*If there is no amsi.dll in current process, this bof will not load it to the process.*

**Update on 18 Aug 2022**

- Added a new version doing indirect syscalls for NtApi

**Update on 30 Sep 2022**

- Added callback unhook on syscall version

## Usage - Cobalt Strike
Load patchit.cna
```
Check if AMSI & ETW are patched:
beacon> patchit check

Patch both AMSI and ETW:
beacon> patchit all

Patch AMSI:
beacon> patchit amsi

Patch ETW:
beacon> patchit etw

Revert both AMSI and ETW:
beacon> patchit revertAll

Patch AMSI:
beacon> patchit revertAmsi

Patch ETW:
beacon> patchit revertEtw
```


## Screenshot examples

Run patchit check when amsi.dll is not loaded:<br>
![image](https://user-images.githubusercontent.com/21979646/184657456-04beae27-3ffa-4602-a6d7-b671aeda9f9c.png)

patchit all:<br>
![image](https://user-images.githubusercontent.com/21979646/184657575-0156c5f4-4af9-41e7-ac2d-2d50a82287ca.png)
![image](https://user-images.githubusercontent.com/21979646/184661310-8fbcd2ab-b1d1-45a3-b413-581da0eb4dcf.png)
![image](https://user-images.githubusercontent.com/21979646/184661321-510d617b-b27a-49f5-82cf-409750afe769.png)


patchit revertAll:<br>
![image](https://user-images.githubusercontent.com/21979646/184657705-a225f6f8-66cf-408e-b0f3-1166adf43a71.png)

## Compile
`make`

## Reference
* https://download.cobaltstrike.com/aggressor-script/index.html
* https://blog.xpnsec.com/hiding-your-dotnet-etw/
* https://rastamouse.me/memory-patching-amsi-bypass/
* https://github.com/Cobalt-Strike/unhook-bof (Big thanks to [@s4ntiago_p](https://twitter.com/s4ntiago_p) on demonstrating how to do indirect syscalls in BOF)
