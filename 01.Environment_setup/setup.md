# here is how to install the multipass 
https://multipass.run/docs/install-multipass

## setup for (Mac)
### multipass
*first you have to install brew if not*
(vscode <---->ssh<---->multipass)
- brew instal --cask multipass
- multipass shell
     *(ip address) is import for the communition with vs code*
- sudo nano/etc/ssh/sshd_config
    *(first enbale the line in code code )line 62 -- change the PermitRootLogin to yes-- save and exit.*
- sudo systemctl ddaemon-reload
- sudo service ssh restart
- sudo passwd ubuntu<br>
    *(insert the password ) make sure note it , it will be user in future*
- hostname -i
### vs code 
-  add the Remote Development package
-  SSH *(ifn not showing SSH enable Remotes(Tunnels/SSH) from Top Remote Explorer)*
    + button 
    - pannel open( ubuntu@id-address)<br>
        *here ubuntu is user name*
    - copyt the ip address of the ***Multipass*** add on the vs code 
    - click on the refresh button of the SSH
    - click on the arrow button (-->)
    - enter the password<br>
    *terminal will be open now in the vs code*




## setup for (linux )
### multipass
*first you have to install multipass if not to avoid confilit with the original os*
(vscode <---->ssh<---->multipass)
- sudo apt-get update
- sudo snap install multipass
- multipass shell

- sudo nano/etc/ssh/sshd_config
    *(first enbale the line in code code )line 62 -- change the PermitRootLogin to yes-- save and exit.*
- sudo systemctl ddaemon-reload
- sudo service ssh restart
- sudo passwd ubuntu<br>
    *(insert the password ) make sure note it , it will be user in future*
- hostname -i

### vs code 
-  add the Remote Development package
-  SSH *(ifn not showing SSH enable Remotes(Tunnels/SSH) from Top Remote Explorer)*
    + button 
    - pannel open( ubuntu@id-address)<br>
        *here ubuntu is user name*
    - copyt the ip address of the ***Multipass*** add on the vs code 
    - click on the refresh button of the SSH
    - click on the arrow button (-->)
    - enter the password<br>
    *terminal will be open now in the vs code*
## setup for (windows )
### virtualbox
*( intall virtual box if not installeed )*<br>
    (https://multipass.run/docs/install-multipass)

### multipass
i
*first you have to install multipass if not to avoid confilit with the original os*
(vscode <---->ssh<---->multipass)
- first download the multipass instaaller (https://multipass.run/docs/install-multipass)
- go to the start of the windows os(Host) type *cmd*
- ##### in Host  terminal 

    - multipass networks
    - multipass launch --network Wi-Fi --name primary 
    - (Next: <br>
        - setup the primry machine to accept SSH connection using password.
            -  edit a file and restart few services)
        

- sudo snap install multipass
- multipass shell

- sudo nano/etc/ssh/sshd_config
    *(first enbale the line in code code )line 62 -- change the PermitRootLogin to yes-- save and exit.*
- sudo systemctl ddaemon-reload
- sudo service ssh restart
- sudo passwd ubuntu<br>
    *(insert the password ) make sure note it , it will be user in future*
- hostname -i

### vs code 
-  add the Remote Development package
-  SSH *(ifn not showing SSH enable Remotes(Tunnels/SSH) from Top Remote Explorer)*
    + button 
    - pannel open( ubuntu@id-address)<b>
        *here ubuntu is user name*
    - copyt the ip address of the ***Multipass*** add on the vs code 
    - click on the refresh button of the SSH
    - click on the arrow button (-->)
    - enter the password<br>
    *terminal will be open now in the vs code*


