//��һ��԰��ʾ�޼�¼�Ļ�������home5��¼��ǰ�ص�Ϊ�ؼ�԰�ص�
inherit F_CLEAN_UP;
int main(object me){
  object env = environment(me);
  if(strsrch(base_name(env),"data")!=-1){
  me->set("home_name",base_name(env));	
  me->save();
  tell_object(me,"���"+env->short()+"���óɷ��ؼ�԰�ĵص�\n");
   return 1;
   }else{
  tell_object(me,"�����õĵص㲻�����֮��\n");
 return 0;
}

}