import wget
import os
urls = (r"https://github.com/Loyalsoldier/v2ray-rules-dat/releases/latest/download/geoip.dat",
        r"https://github.com/Loyalsoldier/v2ray-rules-dat/releases/latest/download/geosite.dat")
for url in urls:
    target_path = os.path.join(r"D:\RogerZhang\v2ray", url.split('/')[-1])
    print(url, target_path)
    wget.download(url, target_path)
