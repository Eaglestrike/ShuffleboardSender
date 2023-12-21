#pragma once

#include "Util/thirdparty/simplevectors.hpp"
#include "ShuffleboardSender/ShuffleboardItem.h"

template<> class ShuffleboardItem<svector::Vector2D>: public BasicShuffleboardItem{
    public:
        ShuffleboardItem(ItemData data, svector::Vector2D* value):
            BasicShuffleboardItem(data)
        {
            value_ = value;

            if(data_.tab){
                frc::ShuffleboardLayout* pointLayout = ShuffleboardHelper::createList(data);
                entry_[0] = pointLayout->Add("X", value->x()).GetEntry();   
                entry_[1] = pointLayout->Add("Y", value->y()).GetEntry();
            }
        }

        bool itemHasChanged() override{
            svector::Vector2D newVal = *value_;
            bool hasChanged = (prevVal_ != newVal);
            prevVal_ = newVal;
            return hasChanged;
        }

        void enable(frc::ShuffleboardTab* tab) override{
            for(auto &component :tab->GetComponents()){
                if(component->GetTitle() == data_.name){
                    return;
                }
            }
            data_.tab = tab;
            frc::ShuffleboardLayout* pointLayout = ShuffleboardHelper::createList(data_);
            entry_[0] = pointLayout->Add("X", value_->x()).GetEntry();   
            entry_[1] = pointLayout->Add("Y", value_->y()).GetEntry();
        }

        void disable() override{

        }
        
    private:
        void send() override{
            entry_[0]->SetDouble(value_->x());
            entry_[1]->SetDouble(value_->y());
        }

        void edit() override{
            value_->x(entry_[0]->GetDouble(value_->x()));
            value_->y(entry_[1]->GetDouble(value_->y()));
        }

        svector::Vector2D prevVal_;
        svector::Vector2D* value_;
        nt::GenericEntry* entry_[2]; //[x, y]
};