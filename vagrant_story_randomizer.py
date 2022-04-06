import mmap
import os
import random
import os.path
import subprocess
import sys
import time
zones = ["ZONE009.ZND", "ZONE011.ZND", "ZONE012.ZND", "ZONE013.ZND", "ZONE014.ZND", "ZONE015.ZND", "ZONE017.ZND", "ZONE022.ZND", "ZONE024.ZND", "ZONE028.ZND", "ZONE030.ZND", "ZONE032.ZND", "ZONE040.ZND", "ZONE048.ZND", "ZONE049.ZND", "ZONE050.ZND", "ZONE051.ZND", "ZONE052.ZND", "ZONE053.ZND", "ZONE055.ZND", "ZONE056.ZND"]
l1 = ["MAP009.MPD", "MAP010.MPD", "MAP011.MPD", "MAP012.MPD", "MAP013.MPD", "MAP014.MPD", "MAP015.MPD", "MAP016.MPD", "MAP018.MPD", "MAP019.MPD", "MAP020.MPD", "MAP021.MPD", "MAP022.MPD", "MAP024.MPD", "MAP412.MPD"]
l2 = ["MAP025.MPD"]
l3 = ["MAP026.MPD", "MAP408.MPD"]
l4 = ["MAP028.MPD", "MAP029.MPD", "MAP030.MPD", "MAP031.MPD", "MAP032.MPD", "MAP033.MPD", "MAP034.MPD", "MAP036.MPD", "MAP037.MPD", "MAP039.MPD", "MAP040.MPD", "MAP041.MPD", "MAP042.MPD", "MAP043.MPD", "MAP044.MPD", "MAP045.MPD"]
l5 = ["MAP046.MPD"]
l6 = ["MAP047.MPD", "MAP048.MPD", "MAP049.MPD", "MAP050.MPD", "MAP051.MPD", "MAP052.MPD", "MAP053.MPD", "MAP054.MPD", "MAP055.MPD", "MAP058.MPD", "MAP059.MPD"]
l7 = ["MAP061.MPD"]
l8 = ["MAP063.MPD", "MAP067.MPD", "MAP069.MPD"]
l9 = ["MAP079.MPD", "MAP080.MPD", "MAP081.MPD", "MAP083.MPD", "MAP084.MPD", "MAP088.MPD", "MAP090.MPD", "MAP094.MPD"]
l10 = ["MAP106.MPD", "MAP108.MPD", "MAP109.MPD", "MAP111.MPD", "MAP112.MPD", "MAP114.MPD", "MAP115.MPD", "MAP116.MPD", "MAP117.MPD", "MAP118.MPD", "MAP119.MPD", "MAP120.MPD", "MAP121.MPD", "MAP122.MPD", "MAP123.MPD"]
l11 = ["MAP140.MPD", "MAP142.MPD", "MAP144.MPD"]
l12 = ["MAP148.MPD", "MAP149.MPD", "MAP150.MPD", "MAP153.MPD", "MAP154.MPD", "MAP157.MPD", "MAP158.MPD", "MAP159.MPD", "MAP160.MPD", "MAP163.MPD", "MAP164.MPD", "MAP165.MPD", "MAP166.MPD"]
l13 = ["MAP180.MPD", "MAP181.MPD", "MAP182.MPD", "MAP184.MPD", "MAP185.MPD", "MAP188.MPD", "MAP189.MPD", "MAP190.MPD", "MAP192.MPD", "MAP195.MPD", "MAP196.MPD", "MAP197.MPD", "MAP198.MPD", "MAP199.MPD", "MAP201.MPD", "MAP202.MPD", "MAP203.MPD"]
l14 = ["MAP221.MPD", "MAP222.MPD", "MAP223.MPD", "MAP225.MPD", "MAP227.MPD", "MAP228.MPD", "MAP229.MPD", "MAP230.MPD", "MAP231.MPD", "MAP232.MPD", "MAP233.MPD", "MAP235.MPD", "MAP236.MPD", "MAP237.MPD", "MAP238.MPD", "MAP239.MPD", "MAP240.MPD", "MAP241.MPD", "MAP242.MPD", "MAP244.MPD", "MAP245.MPD", "MAP246.MPD"]
l15 = ["MAP247.MPD", "MAP248.MPD", "MAP249.MPD", "MAP250.MPD", "MAP251.MPD", "MAP252.MPD", "MAP253.MPD", "MAP254.MPD", "MAP255.MPD", "MAP256.MPD", "MAP257.MPD", "MAP258.MPD", "MAP259.MPD"]
l16 = ["MAP260.MPD", "MAP261.MPD", "MAP262.MPD", "MAP263.MPD", "MAP264.MPD", "MAP265.MPD", "MAP266.MPD", "MAP267.MPD", "MAP269.MPD", "MAP270.MPD", "MAP272.MPD", "MAP273.MPD", "MAP274.MPD", "MAP275.MPD", "MAP277.MPD", "MAP279.MPD", "MAP281.MPD", "MAP282.MPD"]
l17 = ["MAP284.MPD", "MAP285.MPD", "MAP286.MPD", "MAP288.MPD", "MAP289.MPD", "MAP290.MPD", "MAP292.MPD", "MAP293.MPD", "MAP294.MPD", "MAP295.MPD", "MAP296.MPD", "MAP297.MPD", "MAP298.MPD", "MAP300.MPD", "MAP302.MPD", "MAP303.MPD", "MAP304.MPD", "MAP305.MPD", "MAP306.MPD", "MAP307.MPD", "MAP308.MPD", "MAP309.MPD", "MAP310.MPD"]
l18 = ["MAP351.MPD", "MAP352.MPD", "MAP353.MPD", "MAP354.MPD", "MAP355.MPD", "MAP356.MPD", "MAP357.MPD", "MAP358.MPD"]
l19 = ["MAP312.MPD", "MAP314.MPD", "MAP315.MPD", "MAP316.MPD", "MAP317.MPD", "MAP318.MPD", "MAP319.MPD", "MAP320.MPD", "MAP321.MPD", "MAP322.MPD", "MAP323.MPD", "MAP324.MPD", "MAP325.MPD", "MAP326.MPD", "MAP328.MPD", "MAP329.MPD", "MAP331.MPD", "MAP332.MPD", "MAP333.MPD", "MAP334.MPD", "MAP336.MPD", "MAP337.MPD", "MAP338.MPD", "MAP339.MPD", "MAP340.MPD", "MAP342.MPD"]
l20 = ["MAP360.MPD", "MAP362.MPD", "MAP365.MPD", "MAP366.MPD", "MAP367.MPD", "MAP368.MPD", "MAP369.MPD", "MAP371.MPD", "MAP373.MPD", "MAP375.MPD", "MAP377.MPD", "MAP378.MPD", "MAP379.MPD", "MAP380.MPD", "MAP381.MPD"]
l21 = ["MAP382.MPD", "MAP383.MPD", "MAP384.MPD", "MAP385.MPD", "MAP386.MPD", "MAP387.MPD", "MAP388.MPD", "MAP389.MPD", "MAP390.MPD", "MAP391.MPD", "MAP392.MPD", "MAP394.MPD", "MAP395.MPD", "MAP396.MPD", "MAP397.MPD", "MAP398.MPD", "MAP399.MPD", "MAP402.MPD", "MAP403.MPD", "MAP404.MPD", "MAP405.MPD", "MAP407.MPD"]
map_list = [l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21]
com = "8376858345484948"
is_vs = False
start_range = 0
filepath = str(os.getcwd())
print("============================")
print("Instructions:")
print("1) Insert your Vagrant Story bin file into the unzipped randomizer folder.")
print("2) Open vagrant_story_randomizer.")
print("3) Enter the name of your Vagrant Story bin file.")
print("4) Let the randomizer run. It will tell you when the process is completed, then close itself after 3 seconds.")
print("============================")
game = input("Please enter the ROM file name: ")
while (is_vs == False):
    rom_com = ""
    if ((os.path.exists(filepath + "\\" + game) == False) or (os.path.exists(game) == False)):
        print("File not found!")
        game = input("Please enter the ROM file name: ")
    else:
        with open(game, "r+b") as f:
            mm = mmap.mmap(f.fileno(), 0)
            for index in range(37696, 37704):
                rom_com += str(mm[index])
            if rom_com == com:
                is_vs = True
            else:
                print("This isn't Vagrant Story!")
                game = input("Please enter the ROM file name: ")
print("ROM accepted.")
print("Please wait...")
zone_dir = filepath + "\\ZONES\\"
map_dir = filepath + "\\MAPS\\"
for index in range(len(map_list)):
    with open(zone_dir + zones[index], "r+b") as f:
        mm = mmap.mmap(f.fileno(), 0)
        hex_1 = mm[13]
        hex_2 = mm[12]
        para2 = int((int(f'0x{hex_1:x}{hex_2:x}', 0) / 1132))
    for mapd in map_list[index]:
        with open(map_dir + mapd, "r+b") as f:
            size = int((os.path.getsize(map_dir + mapd)) - 1)
            mm = mmap.mmap(f.fileno(), 0)
            quo_numer = mm[36]
            if mm[37] > 0:
                quo_numer = int(hex(mm[36] + 256), 0)
            for byte in range((size - 35), ((size - (38 * int(quo_numer / 40))) - 40), -40):
                item = random.randint(0, (para2 - 1))
                if item == mm[byte]:
                    while item == mm[byte]:
                        item = random.randint(0, (para2 - 1))
                mm[byte] = item
            os.system('start /min cmd /c ' + '"psx-mode2-en.exe "' + game + '" /MAP/' + mapd + ' "' + map_dir + mapd + '"" ')
            mm.close()
print("Randomization complete!")
time.sleep(3) 

                
                
                
                