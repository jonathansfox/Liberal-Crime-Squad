#ifndef CLIP_TYPE_H
#define CLIP_TYPE_H0
class ClipType : public ItemType
{
   public:
      explicit ClipType(MCD_STR xmlstring);
	  thisItemIs whatIsThis() const { return THIS_IS_CLIP; } 
      int get_ammoamount() const { return ammo_; }
   private:
      int ammo_;
};
#endif //CLIP_TYPE_H
