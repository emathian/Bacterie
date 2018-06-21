#----------------------
# Dvarie = 0
# ---------------------
rm(list=ls())

# --------------------- D=0

p <- read.table("./csv/sm_a017_DT_50_Diff",sep=";",dec=".")
p2 <- read.table("./csv/A_18_33_Dvarie.csv",sep=";",dec=".")
p3 <- read.table("./csv/mut34a50.csv",sep=";",dec=".")

p <- rbind(p,p2)
p <- rbind(p,p3)

rm(p3)
rm(p2)

names(p)[names(p)=="V1"] <- "popB"
names(p)[names(p)=="V2"] <- "popA"
names(p)[names(p)=="V3"] <- "Trenew"
names(p)[names(p)=="V4"] <- "A"
names(p)[names(p)=="V5"] <- "D"

D_poss <- c(0,0.02,0.04,0.06,0.08,0.1)

p0 <- p[p$D==D_poss[2],]

extinction0 = (p0$popB == 0 & p0$popA == 0)
exclusion0 = (p0$popB== 0 & p0$popA != 0) 
exclusion_elargie0 = (p0$popB < 0.1*p0$popA & p0$popA != 0)
cohabitation0 = (p0$popB != 0 & p0$popA != 0)

#----------------------
# D = 0
# ---------------------
plot(p0$A[extinction0]~p0$Trenew[extinction0],
     pch=15,col='red',ylim=c(0,70),
     main=c("Etat final de la population pour D =",D_poss[2]) ,
     xlab='T',ylab = 'A(init)')
points(p0$A[cohabitation0]~p0$Trenew[cohabitation0],pch=15,col='green')
points(p0$A[exclusion_elargie0]~p0$Trenew[exclusion_elargie0],pch=15,col='yellow')
points(p0$A[exclusion0]~p0$Trenew[exclusion0],pch=15,col='orange')
legend('topright',col=c('red','orange','yellow','green'),pch=c(15,15,15,15),legend=c('Extinction','Exclusion','Exclusion élargie','Cohabitation'),ncol = 2)

