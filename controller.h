#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QRect>
#include <QSettings>
#include <QDir>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);

    Q_INVOKABLE void recordScreen(QRect rec,
                             QString fileName,
                             int duration,
                             QString comm,
                             bool recordAudio,
                             bool recordCursor);

    Q_INVOKABLE void saveConfig(const QRect &rec,
                                const QString &savePath,
                                const QString &fileFormat,
                                bool useDuration,
                                int duration,
                                bool useCommand,
                                const QString &command,
                                bool recordAudio,
                                bool recordCursor);

    Q_INVOKABLE QRect getRecordRect() const;
    Q_INVOKABLE QString getSavePath() const;
    Q_INVOKABLE QString getFileFormat() const;
    Q_INVOKABLE bool useDuration() const;
    Q_INVOKABLE int duration() const;
    Q_INVOKABLE bool useCommand() const;
    Q_INVOKABLE QString command() const;
    Q_INVOKABLE bool recordAudio() const;
    Q_INVOKABLE bool recordCursor() const;

signals:
    void recordFinished(int exitCode, QString errorString);

private slots:
    void onRecordFinish();

private:
    void initSettings();

private:
    QSettings *m_settings = NULL;
    const QString DEFAULT_SAVE_PATH = QDir::homePath() + "/Gbyzanz";
};

#endif // CONTROLLER_H