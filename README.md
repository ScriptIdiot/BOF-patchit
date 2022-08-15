# Cobalt Strike BOF - patchit

An all-in-one BOF to patch, check and revert AMSI and ETW for x64 process. Wrote this to avoid redundant AMSI / ETW patch.

Currently, it only checks / patches the first few lines of AmsiScanBuffer and EtwEventWrite, additional methods can be added easily to the source code.

*If there is no amsi.dll in current process, this bof will not load it to the process.*


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

patchit revertAll:<br>
![image](https://user-images.githubusercontent.com/21979646/184657705-a225f6f8-66cf-408e-b0f3-1166adf43a71.png)

## Compile
`make`

## Reference
* https://download.cobaltstrike.com/aggressor-script/index.html
* https://blog.xpnsec.com/hiding-your-dotnet-etw/
* https://rastamouse.me/memory-patching-amsi-bypass/