# Avonlea MUD

## Installation
From the lima README: 
```bash
git clone --recurse-submodules https://github.com/limalib/lima -b stable
```
Change the MUD name in ``adm/dist/config`` to anything but the default.

Run the server:
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
See [QUESTS.md](docs/QUESTS.md). 
