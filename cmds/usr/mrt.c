
#include <ansi.h>
inherit F_CLEAN_UP;
#define PAT "/log/adm/mrt"
int main(object me, string arg)
{
int diff=0;
int i,ii,iii,qd,times;
string is,msg,skills,name,*line;
object npc,where,room;
mapping skill;
where = environment(me);
room = load_object("/d/city/mingrt");
qd=room->query("mrt")*100;
if(!arg){
iii=file_size(PAT);
log_file("adm/mrt",sprintf(""));	
if(iii<1)
return notify_fail(HIR"��ʱû������ս�����ã�ָ�kills ��ʼ��ս��\n"NOR);		
is = read_file(PAT);	
line = explode(is,"\n");
msg="����������ս����"ZJBR;
for(i=0;i<10;i++){
sscanf(line[i],"%s=%d",name,times);
msg+="��"+(i+1)+"����"+name+"����ʱ "+times+"��"ZJBR;
}
msg=ZJOBLONG+msg+"Ŀǰ�����ø���ǿ��%"+to_int(qd)+"������ǿ��%100"ZJBR"��ȷ��������ս��\n";
msg+=ZJOBACTS2+ZJMENUF(1,1,9,32);
msg+="��ս:kills\n";
write(msg+NOR);
}

return 1;
}


