/********************************************************************************
** Form generated from reading UI file 'cardeffects.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDEFFECTS_H
#define UI_CARDEFFECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardViewerUI
{
public:
    QWidget *centralWidget;
    QFrame *SelectCardFrame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *SelectCardLayout;
    QComboBox *SelectCardCombo;
    QLabel *SelectCardOrLabel;
    QLineEdit *SelectCardSearchBar;
    QPushButton *SelectCardSearchButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *CardViewerCloseButton;
    QFrame *EffectDescrFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *EffectDescrLabel;
    QScrollArea *EffectDescr;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CardViewerUI)
    {
        if (CardViewerUI->objectName().isEmpty())
            CardViewerUI->setObjectName(QStringLiteral("CardViewerUI"));
        CardViewerUI->resize(522, 439);
        centralWidget = new QWidget(CardViewerUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SelectCardFrame = new QFrame(centralWidget);
        SelectCardFrame->setObjectName(QStringLiteral("SelectCardFrame"));
        SelectCardFrame->setGeometry(QRect(30, 20, 471, 51));
        SelectCardFrame->setFrameShape(QFrame::StyledPanel);
        SelectCardFrame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(SelectCardFrame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 471, 51));
        SelectCardLayout = new QHBoxLayout(horizontalLayoutWidget);
        SelectCardLayout->setSpacing(6);
        SelectCardLayout->setContentsMargins(11, 11, 11, 11);
        SelectCardLayout->setObjectName(QStringLiteral("SelectCardLayout"));
        SelectCardLayout->setSizeConstraint(QLayout::SetFixedSize);
        SelectCardLayout->setContentsMargins(0, 0, 0, 0);
        SelectCardCombo = new QComboBox(horizontalLayoutWidget);
        SelectCardCombo->setObjectName(QStringLiteral("SelectCardCombo"));

        SelectCardLayout->addWidget(SelectCardCombo);

        SelectCardOrLabel = new QLabel(horizontalLayoutWidget);
        SelectCardOrLabel->setObjectName(QStringLiteral("SelectCardOrLabel"));
        SelectCardOrLabel->setMaximumSize(QSize(10, 200));

        SelectCardLayout->addWidget(SelectCardOrLabel);

        SelectCardSearchBar = new QLineEdit(horizontalLayoutWidget);
        SelectCardSearchBar->setObjectName(QStringLiteral("SelectCardSearchBar"));
        SelectCardSearchBar->setMinimumSize(QSize(200, 0));
        SelectCardSearchBar->setMaximumSize(QSize(200, 16777215));

        SelectCardLayout->addWidget(SelectCardSearchBar);

        SelectCardSearchButton = new QPushButton(horizontalLayoutWidget);
        SelectCardSearchButton->setObjectName(QStringLiteral("SelectCardSearchButton"));
        SelectCardSearchButton->setMaximumSize(QSize(35, 16777215));

        SelectCardLayout->addWidget(SelectCardSearchButton);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 350, 471, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        CardViewerCloseButton = new QPushButton(horizontalLayoutWidget_3);
        CardViewerCloseButton->setObjectName(QStringLiteral("CardViewerCloseButton"));
        CardViewerCloseButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(CardViewerCloseButton, 0, Qt::AlignRight);

        EffectDescrFrame = new QFrame(centralWidget);
        EffectDescrFrame->setObjectName(QStringLiteral("EffectDescrFrame"));
        EffectDescrFrame->setGeometry(QRect(30, 80, 471, 261));
        EffectDescrFrame->setFrameShape(QFrame::StyledPanel);
        EffectDescrFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(EffectDescrFrame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 231, 241));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        EffectDescrLabel = new QLabel(verticalLayoutWidget);
        EffectDescrLabel->setObjectName(QStringLiteral("EffectDescrLabel"));

        verticalLayout_2->addWidget(EffectDescrLabel);

        EffectDescr = new QScrollArea(verticalLayoutWidget);
        EffectDescr->setObjectName(QStringLiteral("EffectDescr"));
        EffectDescr->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 227, 218));
        EffectDescr->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(EffectDescr);

        CardViewerUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CardViewerUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 522, 21));
        CardViewerUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CardViewerUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CardViewerUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CardViewerUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CardViewerUI->setStatusBar(statusBar);

        retranslateUi(CardViewerUI);

        QMetaObject::connectSlotsByName(CardViewerUI);
    } // setupUi

    void retranslateUi(QMainWindow *CardViewerUI)
    {
        CardViewerUI->setWindowTitle(QApplication::translate("CardViewerUI", "CardEffects - Card Viewer", 0));
        SelectCardCombo->clear();
        SelectCardCombo->insertItems(0, QStringList()
         << QApplication::translate("CardViewerUI", "Select a card", 0)
        );
        SelectCardOrLabel->setText(QApplication::translate("CardViewerUI", "or", 0));
        SelectCardSearchBar->setText(QApplication::translate("CardViewerUI", "Search for a card", 0));
        SelectCardSearchButton->setText(QApplication::translate("CardViewerUI", "OK", 0));
        CardViewerCloseButton->setText(QApplication::translate("CardViewerUI", "Close", 0));
        EffectDescrLabel->setText(QApplication::translate("CardViewerUI", "Effect:", 0));
    } // retranslateUi

};

namespace Ui {
    class CardViewerUI: public Ui_CardViewerUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDEFFECTS_H
