inherit F_CLEAN_UP;
int main(object me, string arg)
{

  if(arg){
  me->set("beast/beast_id",arg);	
  me->save();
  tell_object(me,"��ʹ�û�����ʱ���Զ��ٻ�idΪ"+arg+"�Ļ�ħ��\n");
   return 1;
   }else{
  tell_object(me,"��Ҫ��¼ʲôid\n");
 return 0;
}

}