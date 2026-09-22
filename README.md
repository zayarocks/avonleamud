# Avonlea MUD

## Installation
From the lima README: 
```bash
git clone --recurse-submodules https://github.com/limalib/lima -b stable
```

## Running the MUD server
Change the MUD name in in ``adm/dist/config.`` 
```
cd lima/adm/dist
./rebuild
./run
```

Find and kill running instances of FluffOS.
```
pgrep -af 'fluffos|driver'
kill [PID]
```

## Quests
See [QUESTS.md]. 
