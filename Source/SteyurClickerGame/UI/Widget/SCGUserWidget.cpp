// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "UI/Widget/SCGUserWidget.h"

void USCGUserWidget::SetWidgetController(UObject* InWidgetController)
{
    WidgetController = InWidgetController;
    WidgetControllerSet();
}

void USCGUserWidget::WidgetControllerSet_Implementation()
{

}
