Imports System.IO
Imports System.IO.Compression
Imports System.Windows.Forms
Imports System.Windows.Resources
Imports System.Reflection
Class MainWindow
    Dim glutEnabled As Boolean
    Dim DPIEnabled As Boolean
    Dim d3d12Enabled As Boolean
    Dim dataPath As String
    Dim gamePath As String = Environment.CurrentDirectory
    Dim archive As ZipArchive
    Private Sub MainWindow_Loaded(sender As Object, e As RoutedEventArgs) Handles Me.Loaded

        If File.Exists("optimizeData") Then
            statusLabel.Foreground = Brushes.Green
            statusLabel.Content = "已找到优化档案。" + Environment.NewLine + "Optimization Data Found."
            dataPath = gamePath + "\optimizeData"
            archive = ZipFile.OpenRead(dataPath)
        Else
            Dim unused = FileIO.FileSystem.GetFileInfo(Forms.Application.ExecutablePath).Length
            If unused > 11537806 Then
                dataPath = Forms.Application.ExecutablePath
                'MsgBox(String.Join(",", Assembly.GetExecutingAssembly().GetManifestResourceNames().ToArray()))
                Dim asm As Assembly = Assembly.GetExecutingAssembly()
                archive = New ZipArchive(asm.GetManifestResourceStream("SuperHexagonOptimize.optimizeData"), ZipArchiveMode.Read)
                statusLabel.Foreground = Brushes.Green
                statusLabel.Content = "优化档案已内置。" + Environment.NewLine + "Optimization Data Inside."
            Else
                statusLabel.Foreground = Brushes.Red
                statusLabel.Content = "未找到优化档案。" + Environment.NewLine + "Optimization Data Missing."
            MsgBox("优化档案缺失。请检查是否下载或解压完整。请解压到游戏目录运行。" + Environment.NewLine + "Optimization data missing. Please extract all files to game directory.",, "关键错误 Critical Error")
        End If
        End If
        If File.Exists("superhexagon.exe") Then
            statusLabel2.Foreground = Brushes.Green
            statusLabel2.Content = "已找到游戏文件。" + Environment.NewLine + "Game Executable Found."
        Else
            Dim f As New FolderBrowserDialog
            f.Description = "选择游戏目录 Select the directory of game."
            f.ShowNewFolderButton = False
            If f.ShowDialog() = Forms.DialogResult.OK Then
                Directory.SetCurrentDirectory(f.SelectedPath)
                gamePath = f.SelectedPath
                If File.Exists("superhexagon.exe") Then
                    statusLabel2.Foreground = Brushes.Green
                    statusLabel2.Content = "已找到游戏文件。" + Environment.NewLine + "Game Executable Found."
                    Try
                        File.Create(gamePath + "\PermissionTest")
                    Catch ex As Exception
                        MsgBox("权限不足，请使用管理员权限运行。" + Environment.NewLine + "Permission denied. Please run in administrator.",, "关键错误 Critical Error")
                    End Try
                Else
                    statusLabel2.Foreground = Brushes.Red
                    statusLabel2.Content = "选择的文件夹内没有游戏。" + Environment.NewLine + "No game in selected folder."
                    MsgBox("未找到游戏主程序。请选择正确的游戏目录或直接放到游戏目录运行。" + Environment.NewLine + "Game executable missing. Please select right game path or run in game directory directly.",, "关键错误 Critical Error")
                End If
            Else
                statusLabel2.Foreground = Brushes.Red
                statusLabel2.Content = "用户取消了路径选择。" + Environment.NewLine + "User canceled folder selecting."
            End If
        End If
        If File.Exists("glut32.dll.bak") Then
            glutEnabled = True
            glutBtn.Content = "禁用glut优化 Disable glut optimization"
        End If
        If File.Exists("superhexagon.exe.bak") Then
            DPIEnabled = True
            dpiBtn.Content = "禁用DPI优化 Disable DPI optimization"
        End If
        If File.Exists("dxil.dll") Then
            d3d12Enabled = True
            d3d12Btn.Content = "禁用d3d12优化 Disable d3d12 optimization"
        End If
    End Sub

    Private Sub folderBtn_Click(sender As Object, e As RoutedEventArgs) Handles folderBtn.Click
        Dim f As New FolderBrowserDialog
        f.Description = "选择游戏目录" + Environment.NewLine + "Select the directory of game."
        f.ShowNewFolderButton = False
        If f.ShowDialog() = Forms.DialogResult.OK Then
            Directory.SetCurrentDirectory(f.SelectedPath)
            gamePath = f.SelectedPath
            If File.Exists("superhexagon.exe") Then
                statusLabel2.Foreground = Brushes.Green
                statusLabel2.Content = "已找到游戏文件。" + Environment.NewLine + "Game Executable Found."
                Try
                    File.Create(gamePath + "\PermissionTest")
                Catch ex As Exception
                    MsgBox("权限不足，请使用管理员权限运行。" + Environment.NewLine + "Permission denied. Please run in administrator.",, "关键错误 Critical Error")
                End Try
            Else
                statusLabel2.Foreground = Brushes.Red
                statusLabel2.Content = "选择的文件夹内没有游戏。" + Environment.NewLine + "No game in selected folder."
                MsgBox("未找到游戏主程序。请选择正确的游戏目录或直接放到游戏目录运行。" + Environment.NewLine + "Game executable missing. Please select right game path or run in game directory directly.",, "关键错误 Critical Error")
            End If
        Else
            statusLabel2.Foreground = Brushes.Red
            statusLabel2.Content = "用户取消了路径选择。" + Environment.NewLine + "User canceled folder selecting."
        End If
    End Sub
    Private Sub glutBtn_Click(sender As Object, e As RoutedEventArgs) Handles glutBtn.Click
        If glutEnabled Then
            File.Delete("glut32.dll")
            Rename("glut32.dll.bak", "glut32.dll")
            glutBtn.Content = "启用glut优化 Enable glut optimization"
            glutEnabled = False
        Else
            Rename("glut32.dll", "glut32.dll.bak")
            Dim entry As ZipArchiveEntry = archive.GetEntry("glut32.dll")
            entry.ExtractToFile(gamePath + "\glut32.dll")
            glutBtn.Content = "禁用glut优化 Disable glut optimization"
            glutEnabled = True
        End If
    End Sub

    Private Sub dpiBtn_Click(sender As Object, e As RoutedEventArgs) Handles dpiBtn.Click
        If DPIEnabled Then
            File.Delete("superhexagon.exe")
            Rename("superhexagon.exe.bak", "superhexagon.exe")
            dpiBtn.Content = "启用DPI优化 Enable DPI optimization"
            DPIEnabled = False
        Else
            Rename("superhexagon.exe", "superhexagon.exe.bak")
            Dim entry As ZipArchiveEntry = archive.GetEntry("superhexagon.exe")
            entry.ExtractToFile(gamePath + "\superhexagon.exe")
            dpiBtn.Content = "禁用DPI优化 Disable DPI optimization"
            DPIEnabled = True
        End If
    End Sub

    Private Sub d3d12Btn_Click(sender As Object, e As RoutedEventArgs) Handles d3d12Btn.Click
        If d3d12Enabled Then
            File.Delete("opengl32.dll")
            File.Delete("dxil.dll")
            File.Delete("libglapi.dll")
            d3d12Btn.Content = "启用d3d12优化 Enable d3d12 optimization"
            d3d12Enabled = False
        Else
            Dim entry As ZipArchiveEntry = archive.GetEntry("opengl32.dll")
            entry.ExtractToFile(gamePath + "\opengl32.dll")
            Dim entry2 As ZipArchiveEntry = archive.GetEntry("dxil.dll")
            entry2.ExtractToFile(gamePath + "\dxil.dll")
            Dim entry3 As ZipArchiveEntry = archive.GetEntry("libglapi.dll")
            entry3.ExtractToFile(gamePath + "\libglapi.dll")
            d3d12Btn.Content = "禁用d3d12优化 Disable d3d12 optimization"
            d3d12Enabled = True
        End If
    End Sub
End Class
